
#include <ansi.h>
#include <weapon.h>

inherit STAFF; 

void create()
{
        set_name(  "��" , ({ "staff" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",

"����һ������ͨͨ���ȣ����ϵ���û���κ�����֮����\n"
);
                set("value", 1);
                set("material", "steel");
                set("rigidity", 100000);
                set("weapon_prop/agility", 3); 
                set("weapon_prop/personality", 3); 
		set("weapon_prop/intelligence", 1);
		set("weapon_prop/courage", 3); 
		set("weapon_prop/composure", 3);
        }

        init_staff(120);
        setup();

}
 
void init()
{
	add_action("do_make","remake");
}


int do_make()
{
	object me;
	object obj;
	me=this_player();
	obj=new(__DIR__"commcase");
	obj->move(me);
        destruct(this_object());
	return 1;
}          
  