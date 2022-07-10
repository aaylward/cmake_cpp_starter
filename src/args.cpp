#include "args.h"
#include <boost/program_options.hpp>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

std::unique_ptr<qwk::options> qwk::get_options(int ac, char** av) {
  namespace po = boost::program_options;

  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("debug", po::value<bool>()->default_value(false), "debug?")
    ("standard", po::value<uint8_t>()->default_value(17), "cpp standard")
    ("parser", po::value<bool>()->default_value(false), "include arg parser?")
    ("boost", po::value<std::string>()->default_value("1.78"), "boost version for arg parser");

  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);

  auto o = std::make_unique<qwk::options>();

  if (vm.count("help")) {
    std::cout << desc << std::endl;
    return o;
  }

  if (ac < 2 || strncmp("-", av[1], 1) == 0) {
    std::cout << desc << std::endl;
    return o;
  }

  o->project = std::string(av[1]);

  o->standard = vm["standard"].as<uint8_t>();
  o->debug = vm["debug"].as<bool>();
  o->parser = vm["parser"].as<bool>();
  o->boost_version = vm["boost"].as<std::string>();

  return o;
}
