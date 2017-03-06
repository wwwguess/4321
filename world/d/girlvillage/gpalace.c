//room /u/gilrvillage/gpalace.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "九阴藏秀阁");
        set("long", @LONG
这里是九阴的九阴藏秀阁, 九阴弟子可以在此练功, 不受外派干扰.
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
        if(classname!="九阴派") {
        ob->move("/u/girlvillage/villagehall");
        message_vision(HIW"\n$N被一股无形的九阴罡气挡了回来。\n\n"NOR, ob);
           }             
                         }
}
                                                                                                 