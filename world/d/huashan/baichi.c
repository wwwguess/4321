// baichi.c

inherit ROOM;

void create()
{
        set("short", "�ٳ�Ͽ");
	set("long", @LONG
�߹�ǧ�ߴ���ǰ���ּ���һҪ���İٳ�Ͽ���ٳ�Ͽ����ǧ�ߴ����վ�
������ʮ�ֶ��ͣ��ұ�����������������������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"qianchi",
  "eastup" : __DIR__"laojun",
]));
        set("objects", ([ __DIR__"npc/haoke": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
