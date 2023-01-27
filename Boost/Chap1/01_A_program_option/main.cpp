// TBD

#include <boost/program_options.hpp>
#include <iostream>

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
  // 변수를 나타내는 옵션 생성
  // 문자 설명으로 "All Options"을 설정한다.
  opt::options_description desc("All options");

  // 옵션을 추가할 때, 사용명, 형식, 설명 순으로 설정
  desc.add_options()
    ("apples", opt::value<int>(), "How many apples do you have")
    ("oranges", opt::value<int>(), "How many oranges do you have")
    ("help", "produce help message")
  ;

  // 커맨드라인 인자 저장 변수
  opt::variables_map vm;

  // 인자를 파싱한 후, 저장함
  opt::store(opt::parse_command_line(argc, argv, desc), vm);

  // 파싱 후, 불러오기
  opt::notify(vm);

  // help 옵션 처리
  if (vm.count("help")){
    std::cout << desc << std::endl;
    return 1;
  }

  std::cout << "Fruits count : " << vm["apples"].as<int>() + vm["oranges"].as<int>() << std::endl;
}