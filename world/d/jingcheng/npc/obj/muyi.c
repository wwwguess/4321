#include <ansi.h>
inherit ITEM;
void create()
{
     set_name(YEL "ľ��"NOR, ({ "mu yi","yi"}));
     set_weight(100);
     if (clonep() )
            set_default_object(__FILE__);
        else {
             set("long","һ��������ϸ��Сľ��\n");
               set("unit","��");
               set("value",1000);
       }
}
