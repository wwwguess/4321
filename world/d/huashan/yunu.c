// yunu.c

inherit ROOM;

void create()
{
        set("short", "��Ů��");
	set("long", @LONG
�����ǻ�ɽ���з壬��Ů�塣��Ů�������Ϊƽ�������������ķ��
�վ��������Ϻպ������Ļ�ɽ���ɾ��ڴ˴�����������СС������Ǿ�
����Ů���ˡ�����ϡϡ������ʮ���䷿�ӣ��ǻ�ɽ�ɵĵط��������ο���
�ñ�������ȥ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"zhenyue",
  "east" : __DIR__"yunuci",
  "south" : __DIR__"square",
]));
        set("objects", ([ __DIR__"npc/youke": 3 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
