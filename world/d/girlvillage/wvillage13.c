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
        "north" : __DIR__"wvillage12",
          "south" : __DIR__"wvillage14",
            "west"  : __DIR__"wvillage9",
              "east"  : __DIR__"wvillage1",
]));

        set("outdoors", "girlvillage");
        
        setup();
        replace_program(ROOM);
        
}
                              