
#include <armor.h>
inherit NECK;

void create()
{
        set_name( "�ƽ�����" , ({ "gold ream","ream" }) );
         set("long", "һ�����������Ļƽ����ƣ�����һЩͼ�ڱ�־��\n");
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3000);
                set("no_drop", 1);
                set("material", "gold");
                set("armor_prop/unarmed", 1);
                set("armor_prop/dodge", 1);
        set("wear_msg", "$N��$n�ó����ھ����ϡ�\n");
        }
        setup();
}
