// guihua.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("���", ({ "osmanthus flower", "flower" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "��ժ�Ĺ𻨣��������󵭵������㡣\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(10);
        init_throwing(1);
        setup();
}       
