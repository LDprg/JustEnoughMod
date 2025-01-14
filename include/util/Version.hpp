#ifndef UTIL_VERSION_HPP
#define UTIL_VERSION_HPP

#include <util/Util.hpp>

namespace JEM {
  struct Version {
      int major;
      int minor;
      int patch;

      explicit operator std::string() const {
        return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
      }

      Version() = default;

      Version(int maj, int min, int pat) : major(maj), minor(min), patch(pat) {}

      consteval explicit Version(const char *str) : major(0), minor(0), patch(0) {

        const char *token = str;
        if (*token == '\0') {
          return;
        }

        major = atoi(token);

        do {
          token++;
          if (*token == '\0') {
            return;
          }
        } while (*(token - 1) != '.');

        minor = atoi(token);

        do {
          token++;
          if (*token == '\0') {
            return;
          }
        } while (*(token - 1) != '.');

        patch = atoi(token);
      }
  } __attribute__((aligned(16)));
} // namespace JEM

#endif
