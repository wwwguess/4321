#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name(HIC "�廨��" NOR, ({"needle" }) );
     if ( clonep() )
              set_default_object(__FILE__);
     else {
             set("long", "һ���ϵ������ɵ��廨��\n");
          set("unit", "��");
          set("weight", 30);
	  set("value", 100);
          set("material", "steel");
          set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
          set("unwield_msg", "$N�����е�$n����廨����\n");
          set("material", "iron");
     }
     init_sword(10);
     setup();
}
