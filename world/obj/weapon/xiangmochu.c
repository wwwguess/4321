// xiangmochu.c ��ħ��

#include <weapon.h>
#include <ansi.h>
inherit PESTLE;

void create()
{
        set_name(BLK "��ħ��" NOR, ({ "xiangmo chu", "chu" }));
        set_weight(40000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ����ħ��,ð�ź������˲�������!\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���뱳��ĳ��Ҽ䡣\n");
                set("value", 500);
                set("material", "steel");
        }
        init_pestle(60);
        setup();
}
