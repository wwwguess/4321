#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()

{
     set_name("����", ({"whip"}) );
     set_weight(1000);
     if( clonep() )
             set_default_object(__FILE__);
     else {
     set("unit", "��");
     set("long", "һ������ľΪ��, ��βΪ˿�ķ���\n");
     set("value", 100);
     set("martial", "wood");
     set("wield_msg", "$N�ӱ�����������һ��$n�������С�\n");
     set("unwield_msg", "$N�����е�$n����б���ڱ���������ϡ�\n");
     }
     init_whip(10);
    
     setup();
}
