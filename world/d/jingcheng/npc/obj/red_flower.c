#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"��õ��"NOR,({"hong mei gui","hua","hong","mei gui"}));
    set_weight(10);
     if (clonep() )
      set_default_object(__FILE__);
     else {
      set("ong","һ�����鱼�ŵĺ�õ��");
      set("value",250);
      set("unit","��");
    }
}
