#include "Animate.h"

#define Animate_Choice 2

#if Animate_Choice != 0
int Animate_key = -1; //初始化图标显示帧数
#endif

#if Animate_Choice == 1
#include "img/astronaut.h"
#elif Animate_Choice == 2
#include "img/hutao.h"
#endif

void imgAnim(const uint8_t **Animate_value, uint32_t *Animate_size)
{
#if Animate_Choice != 0
    Animate_key++;
#endif

//太空人起飞
#if Animate_Choice == 1
    *Animate_value = astronaut[Animate_key];
    *Animate_size = astronaut_size[Animate_key];
    if (Animate_key >= 9)
        Animate_key = -1;
//胡桃摇
#elif Animate_Choice == 2
    *Animate_value = hutao[Animate_key];
    *Animate_size = hutao_size[Animate_key];
    if (Animate_key >= 31)
        Animate_key = -1;
#endif
}