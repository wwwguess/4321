inherit ROOM;

void create()
{
        set("short", "ɽ��·");
        set("long", @LONG
����ɽ���е�һ��С�������Ͼ���ѩͤ����������һ��СС
�Ĵ��䡣������������һ���ʯ��ʯ�Ͽ��ż������֡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"villagepath",
    "south"  : "/d/green/road5",
]));
        set("outdoors", "girlvillage");
        
        setup();
        replace_program(ROOM);

}
                            