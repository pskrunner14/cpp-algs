TODO: Refactor and add documentation for all interfaces.

cpp_algs.hpp is responsible for including/packaging all headers from the library codebase and compiling into one shared object file (.so) so add includes for any new modules you introduce in the codebase at the end or in order of dependency.

config.hpp.in will be used by CMAKE at build time to populate any application level variables we'll need in the library ex. version, paths etc.