//room /u/gilrvillage/gpalace.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "���������");
        set("long", @LONG
�����Ǿ����ľ��������, �������ӿ����ڴ�����, �������ɸ���.
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "west" : "/u/girlvillage/villagehall",
        ]));
        set("outdoors", "girlvillage");
        
        setup();
}
void init()
{       object ob;
        string classname;
        
        if( interactive( ob = this_player()))
        {
        classname = ob->query("family/family_name");
        if(classname!="������") {
        ob->move("/u/girlvillage/villagehall");
        message_vision(HIW"\n$N��һ�����εľ���������˻�����\n\n"NOR, ob);
           }             
                         }
}
                                                                                                 