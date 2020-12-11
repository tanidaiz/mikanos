#include <cstdint>

extern "C" void KernelMain(uint64_t frame_buffer_base,
                           uint64_t frame_buffer_size) {
  uint8_t* frame_buffer = reinterpret_cast<uint8_t*>(frame_buffer_base);
  uint8_t time = 0;
  while(1){
    for (uint64_t i = 0; i < frame_buffer_size; ++i) {
      frame_buffer[i] = (uint8_t)(i+time) % 256;
    }
    time++;
  }
  
  while (1) __asm__("hlt");
}
