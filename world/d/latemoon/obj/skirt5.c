#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
       set_name( "��ȹ" , ({ "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
               set("value", 700);
                set("material", "cloth");
                set("armor_prop/armor",2);
        set("wear_msg", "$N��$n�ó�ϵ�����ϡ�\n");
        }
        setup();
}
int wear()
{
     if ((string)this_player()->query("gender") !="Ů��")
           return notify_fail("ֻ��Ů���ſɴ�Ŷ!���̬ѽ! \n");
     else {
           ::wear();
          }
     return 1;

}
