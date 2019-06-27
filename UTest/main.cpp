#include "main.h"

static const int
	V_SIZE = 10,
	RAND_ORDER = (V_SIZE * 1000000); //for numbers < 1000

using String = std::string;
static const String TEST_PATH = "cpp.txt";

void qsort_recursive(String& raw);

String
	unsorted = "ibgehacfdj",
	expected_sorted = "abcdefghij",
	one_char_string = "aaaaaaaaaa",
	zeros_string = "\0\0\0\0\0\0\0\0\0\0",
	zeros_ones_string = "a\0a\0a\0a\0a\0",
	sorted_zeros_ones_string = "a";

inline void print_vector(String & data){
	String::iterator current = data.begin();
	String::iterator end = data.end() - 1;
	if(end - current < 0) return;

	std::cout << "Vector is: ";
	while(current <= end){
		std::cout << *current << " ";
		current++;
	}
	std::cout << std::endl;
}

TEST(sort_test, sort_random_unsorted){
	String raw = unsorted;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == expected_sorted) << "vector not sorted!\n";
}

TEST(sort_test, sort_sorted){
	String raw = expected_sorted;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == expected_sorted) << "vector not sorted!\n";
}

TEST(sort_test, sort_ones_vector){
	String raw = one_char_string;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == one_char_string);
}

TEST(sort_test, sort_zeros_vector){
	String raw = zeros_string;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == zeros_string);
}

TEST(sort_test, sort_zeros_ones_vector){
	String raw = zeros_ones_string;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == sorted_zeros_ones_string);
}

TEST(file_test,file_write){
    String raw = unsorted;
    std::ifstream f;
    f.open(TEST_PATH, std::ios::in);
    ASSERT_TRUE( f.is_open() ) << "Cat open file" ;
   
}

TEST(file_test,file_read){
    String raw = expected_sorted;
    std::ofstream f;
    f.open(TEST_PATH, std::ios::out);
    ASSERT_TRUE(f.is_open()) << "Cat open file" ;
}
	   
TEST(main_test, sort_files){
	String raw = unsorted;
	std::ifstream f;
	f.open(TEST_PATH, std::ios::in);
	f>>raw;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == expected_sorted);
}

void file_read(const String path_to_file, String & data) {
	std::ifstream f;
  f.open(path_to_file, std::ios::in);//точный адрес хранения необходимого файла
  if (f)
    while(!f.eof())
      f>>data;
  else
    std::cout <<"Error!\n";
  f.close();
}

void file_write(const String path_to_file, String & data) {
	std::ofstream n;
  n.open(path_to_file, std::ios::out);;//удаляем данные о предыдущем файле
  if (!(n.is_open()))
    std::cout << "File not find\n";
  else {
    n<<data;//перезаписываем файл
    n.close();
  }
}

void sort_file(const String path_to_file)
{
  String unsorted_local;
  file_write(TEST_PATH, unsorted);
  file_read(TEST_PATH, unsorted_local);
  qsort_recursive(unsorted_local);
  file_write(TEST_PATH, unsorted_local);
}

int main(int argc, char ** argv)
{
	try {
		sort_file(TEST_PATH);
	}
	catch (const char * exception)
	{
		std::cerr << exception;
	}

	try{
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
	catch(const char * exception)
	{
		std::cerr << exception;
	}
}

void qsort_recursive(String & raw) {
	#ifdef DEBUG_FLAG
		const char * path_lib = "../lib/Debug/sort.dll";
	#else
		const char * path_lib = "../lib/Release/sort.dll";
	#endif

 	HINSTANCE hinst_lib = LoadLibrary(path_lib);
	
	if (!hinst_lib){
		throw "Error: can't find sort.dll\n";
	}

	static _qsort_recursive DllFunc = (_qsort_recursive)GetProcAddress(hinst_lib, "qsort_recursive");

	if (!DllFunc){ // Проверяем что удалось получить указатель
		throw "Error: can't find function\n";
	}
	else{
		DllFunc(raw); // вызываем
	}

	FreeLibrary(hinst_lib);
}