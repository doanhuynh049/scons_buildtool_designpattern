#SCons build script for a C++ project

#Define the C++ compiler and linker
env= Environment(CXX='g++', LINK='g++')

#define source file
src = Glob('src/*.cpp') + Glob("include/*.h")

#define build target
exe = env.Program(target='my_executation',source=src)

#define installation target
install_targets =[env.Install('/usr/local/bin', exe)]

#define clean target
clean_target = [exe, env.Dir('build')]
#define the default build target
# Default(exe)


print('Build setting:')
print('CXX:         ',env['CXX'])
print('CXXFLAGS:    ',' '.join(env['CXXFLAGS']))
print('LINK:        ',env['LINK'])
print('Target:      ',exe[0].abspath)

run = env.Command('run', exe, exe[0].abspath)
Default(run)

