project('vkroots', 'cpp', meson_version: '>=0.58.0', default_options: [
  'cpp_std=c++20',
  'warning_level=2',
])

# Add Vulkan dependency
vulkan_dep = dependency('vulkan')

vkroots_dep = declare_dependency(
  include_directories : include_directories('.'),
  version             : meson.project_version(),
  dependencies        : [vulkan_dep],
)

meson.override_dependency('vkroots', vkroots_dep)

install_headers('vkroots.h')

shared_library('my_debug_layer',
  'my_debug_layer.cpp',
  vs_module_defs: 'my_debug_layer.def',
  dependencies : [vkroots_dep, vulkan_dep],
  name_prefix: '')

install_data('my_debug_layer.json')

pkgconfig = import('pkgconfig')
pkgconfig.generate(
  version: meson.project_version(),
  filebase: meson.project_name(),
  name: meson.project_name(),
  description: 'Vulkan layers library',
  subdirs: '.'
)
