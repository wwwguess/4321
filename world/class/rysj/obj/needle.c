#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name(HIC "绣花针" NOR, ({"needle" }) );
     if ( clonep() )
              set_default_object(__FILE__);
     else {
             set("long", "一种上等铁做成的绣花针\n");
          set("unit", "根");
          set("weight", 30);
	  set("value", 100);
          set("material", "steel");
          set("wield_msg", "$N「唰」的一声抽出一根$n握在手中。\n");
          set("unwield_msg", "$N将手中的$n插回绣花绷。\n");
          set("material", "iron");
     }
     init_sword(10);
     setup();
}
