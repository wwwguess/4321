//ywswod.c 
//by dwolf
//97.11.8

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(RED "������" NOR, ({ "yuewang jian", "jian" }));
        set_weight(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����������ɣ�������������ۣ�����������ͬ¯���ɡ�\n");
                set("value", 10000);
                set("material", "greysteel");
                set("wield_msg", "$N��ৡ���һ�����һ���������˵�$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(200);
        setup();
}
