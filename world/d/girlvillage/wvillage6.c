inherit ROOM;

void create()
{
        set("short", "Ů�˴�");
        set("long", @LONG
��äĿ���������ޱ߼ʵ�Ů�˴���������ܣ����ܵľ�ɫ
������߹��ĵط�����һ��������������Ů�˴�����߿��ٴ�����
����Ͷ���������۹⡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"wvillage5",
          "south" : __DIR__"wvillage7",
            "west"  : __DIR__"wvillage2",
              "east"  : __DIR__"wvillage10",
]));

        set("outdoors", "girlvillage");
        set("objects", ([
                __DIR__"npc/thousand_hand" : 1,
        ]) );
        
        setup();
        replace_program(ROOM);
        
}
                
                      