#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"������"NOR,({"nai lan hua","hua"}));
    set_weight(10);
     if (clonep() )
      set_default_object(__FILE__);
    else {
      set("long","һ�������");
      set("value",200);
      set("unit","��");
      }
}
