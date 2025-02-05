#include "vkroots.h"
#include <windows.h>

namespace MyDebugLayer {
  class VkInstanceOverrides {
  public:
    static VkResult CreateInstance(
      PFN_vkCreateInstance              next,
      const VkInstanceCreateInfo*        pCreateInfo,
      const VkAllocationCallbacks*       pAllocator,
            VkInstance*                  pInstance) {
      
      if (pCreateInfo && pCreateInfo->enabledExtensionCount > 0) {
        OutputDebugStringA("Requested Instance Extensions:\n");
        printf("Requested Instance Extensions:\n");
        for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; i++) {
          OutputDebugStringA("  ");
          OutputDebugStringA(pCreateInfo->ppEnabledExtensionNames[i]);
          OutputDebugStringA("\n");
          printf("  %s\n", pCreateInfo->ppEnabledExtensionNames[i]);
        }
      }

      return next(pCreateInfo, pAllocator, pInstance);
    }

    static VkResult CreateDevice(
      const vkroots::VkInstanceDispatch* dispatch,
            VkPhysicalDevice         physicalDevice,
      const VkDeviceCreateInfo*      pCreateInfo,
      const VkAllocationCallbacks*   pAllocator,
            VkDevice*                pDevice) {

      if (pCreateInfo && pCreateInfo->enabledExtensionCount > 0) {
        OutputDebugStringA("Requested Device Extensions:\n");
        printf("Requested Device Extensions:\n");
        for (uint32_t i = 0; i < pCreateInfo->enabledExtensionCount; i++) {
          OutputDebugStringA("  ");
          OutputDebugStringA(pCreateInfo->ppEnabledExtensionNames[i]);
          OutputDebugStringA("\n");
          printf("  %s\n", pCreateInfo->ppEnabledExtensionNames[i]);
        }
      }

      return dispatch->CreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    }
  };
}

VKROOTS_DEFINE_LAYER_INTERFACES(MyDebugLayer::VkInstanceOverrides,
                               vkroots::NoOverrides,
                               vkroots::NoOverrides); 