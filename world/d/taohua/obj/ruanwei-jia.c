// ruanwei-jia.c

#include <armor.h>

#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("��⫼�", ({ "ruanwei jia", "jia" }));
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ϣ���䱦��\n");
                set("material", "cloth");
                set("new_taohua",1);
                set("unit", "��");
                set("value", 500000);
                set("wear_msg", HIY "ֻ����������һ����$N��һ����⫼״������ϡ�\n" NOR);
        set("remove_msg", HIY "$N����⫼����������������۵���СС��һ��\n" NOR);
                set("armor_prop/armor", 500);
        }
 
        setup();
}
