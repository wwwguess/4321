#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(  GRN "���佣" NOR, ({ "zhenwu sword","sword","zhenwu" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",

"�����䵱��ɽ֮��������ͨ����̣��������˻��ǡ�\n"
);
                set("value", 250000);
                set("material", "steel");
                set("rigidity", 1000000);
                set("wield_msg", YEL "�һ��,$N�������Ѷ���һ��ն����ħ��$n��\n" NOR);
                set("unequip_msg", HIY "$N�����е�$n��������Ľ��ʡ�\n" NOR);
        }

     init_sword(400);
        setup();

}
//int query_autoload() { return 1; } 
