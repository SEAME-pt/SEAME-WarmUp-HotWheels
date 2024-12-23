#ifndef ENGINESYSTEM_HPP
#define ENGINESYSTEM_HPP

#include "Crankshaft.hpp"
#include "Motor.hpp"
#include "Piston.hpp"
#include <memory>
#include <vector>

class EngineSystem {
private:
  std::shared_ptr<Motor> motor;
  std::vector<std::shared_ptr<Piston>> pistons;
  std::shared_ptr<Crankshaft> crankshaft;
  bool isRunning;
  int power;

public:
  EngineSystem();
  EngineSystem(std::shared_ptr<Motor> motor,
               const std::vector<std::shared_ptr<Piston>> &pistons,
               std::shared_ptr<Crankshaft> crankshaft);
  EngineSystem(const EngineSystem &other);
  EngineSystem &operator=(const EngineSystem &other);
  ~EngineSystem();

  bool getIsRunning() const;
  int getPower() const;

  void ignite();
  void accelerate();
  void decelerate();
  void shutdown();

  std::string getInfo() const;
  void operate();
};

#endif
