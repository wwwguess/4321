#include <armor.h>
#include <ansi.h>
inherit CLOTH;
 void create()
{
      set_name(HIW"�ױ���"NOR, ({"bai beixin"}));
      set_weight(2000);
       if( clonep() )
           set_default_object(__FILE__);
      else {
              set("unit","��");
              set("value",150);
             set("material", "cloth");
              set("armor_prop/armor",2);
      }
       setup();
 }
