#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
    set_name(HIC "�廨��" NOR, ({"needle" }) );
     if ( clonep() )
              set_default_object(__FILE__);
     else {
             set("long", "һ���ϵ������ɵ��廨��\n");
          set("unit", "Щ");
          set("base_unit", "��");
          set("base_weight", 30);
          set("base_value", 100);
          set("material", "iron");
     }
     set_amount(1);
     init_throwing(30);
     setup();
}
