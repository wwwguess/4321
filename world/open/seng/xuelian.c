//xuelian.c ��ѩ�� seng 3.24

void setup();
inherit ITEM;
void init()
{
add_action("do_eat","eat");
}
void create()
{
set_name("��ѩ��",({"xuelian", "lian"}));
if (clonep())
   set_default_object(__FILE__);
else {
set("unit", "��");
 set("value",500000);
} 
setup();
}
int do_eat(string arg)
{
if (id(arg))
return notify_fail("��������\n");
this_player()->add("food",3000);
this_player()->add("water",3000);
message_vision("$N����һ�ô�ѩ������������!\n");
this_player();
destruct (this_object());
return 1;
}
