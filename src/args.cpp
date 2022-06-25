#include "args.h"
#include <boost/program_options.hpp>
#include <cstdint>
#include <iostream>
#include <string>

namespace cs = cpp_starter;

std::unique_ptr<cs::options> cs::get_options(int ac, char** av) {
  namespace po = boost::program_options;

  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("debug", po::value<bool>()->default_value(false), "debug?")
    ("project", po::value<std::string>(), "project name")
    ("standard", po::value<uint8_t>()->default_value(17), "cpp standard")
    ("parser", po::value<bool>()->default_value(false), "include arg parser?")
    ("boost", po::value<std::string>()->default_value("1.78"), "boost version for arg parser");

  po::variables_map vm;
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);

  auto o = std::make_unique<cs::options>();

  if (vm.count("help")) {
    std::cout << desc << std::endl;
    return o;
  }

  o->standard = vm["standard"].as<uint8_t>();
  o->debug = vm["debug"].as<bool>();
  o->parser = vm["parser"].as<bool>();
  o->boost_version = vm["boost"].as<std::string>();

  if (vm.count("project")) {
    o->project = vm["project"].as<std::string>();
  }
  return o;
}