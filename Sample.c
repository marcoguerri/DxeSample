#include <Uefi.h>

#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>

VOID
EFIAPI
NotifyExitBootServices (
  IN EFI_EVENT  Event,
  IN VOID       *Context
  )
{
  DEBUG((EFI_D_INFO, "[DxeSample] Exit BootService notification.\n"));
}


EFI_STATUS
EFIAPI
SampleDriverInitialize (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
  EFI_STATUS Status;
  EFI_EVENT ExitBootServicesEvent;
  DEBUG((EFI_D_INFO, "[DxeSample] Running DxeSample.\n"));
  Status = gBS->CreateEventEx (
                  EVT_NOTIFY_SIGNAL,
                  TPL_CALLBACK,
                  NotifyExitBootServices,
                  NULL, // Parameter Context can be passed here
                  &gEfiEventExitBootServicesGuid,
                  &ExitBootServicesEvent
                  );
  if(Status != EFI_SUCCESS) {
	DEBUG((EFI_D_INFO, "Could not register ExitBootServices hook.\n"));
  }
  return EFI_SUCCESS;
}
