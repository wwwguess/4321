inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
��������Ѱ��֮����ڰ������ڣ��Ͻ����������ɾ�һ�㣬������������...
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"guyehill",
        ]));
        set("objects", ([
                __DIR__"npc/crane" : 4,
                      ]) );

        setup();
        replace_program(ROOM);
} 
