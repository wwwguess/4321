 // houhuayuan1.c
// by yuer
inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
�����ǹ������ĺ�԰�������˻��ݡ�����Сͯ���ڽ���
������һ�����ŵ�С�ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"neishi",
  "south" : __DIR__"dadian",
  "west":__DIR__"houhuayuan2",
  
]));
        set("objects", ([
                __DIR__"npc/xiaozhao" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "mingjiao" );
        setup();
       
}
int valid_leave(object me, string dir)
{
       
        if (dir == "north" && objectp(present("xiao zhao", environment(me))))
           return notify_fail("С�Ѻȵ�������С��Ĺ뷿�����˲������ڡ�\n");
        return ::valid_leave(me, dir);
}



