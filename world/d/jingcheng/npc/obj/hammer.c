
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("����", ({ "silver hammer", "hammer" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1600);
                set("material", "steel");
                set("long", "һ�Ѽ������صĴ�鳣�Ҫ�Ӷ������������ǵ��й��˵��������ɡ�\n");
                set("weapon_prop/attack", -4);
                set("weapon_prop/defense", 5);
        }
	init_hammer(40);
        setup();

}
