// longsword.c ���컭�

#include <weapon.h>
#include <ansi.h>
inherit HALBERD;

void create()
{
	set_name(GRN "���컭�" NOR, ({ "fangtian huaji", "ji","huaji" }));
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ�����컭�,ð�ź������˲�������!\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���뱳��ĳ��Ҽ䡣\n");
                set("value", 500);
                set("material", "steel");
        }
        init_halberd(40);
        setup();
}
