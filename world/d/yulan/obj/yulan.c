#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("玉兰花", ({ "yulan" }) );
        set_weight(800000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵白玉雕成的玉兰花，上面刻着几行小字：
据说有两位著名的武林高手在与魔教的比武中遭人暗算，从此隐居山林，苦练武功，
发誓终有一天要报此仇，他们两人中悲愤云烟隐居在玉兰山庄，朦胧奇剑隐居在月
亮谷，不过听说去月亮谷，如果你不会游识神通将有去无回。\n");
                set("value", 3);
                //set("material", "gold");
        }
        init_hammer(65);
        setup();
}
