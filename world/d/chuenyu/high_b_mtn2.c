// Room: /d/chuenyu/high_b_mtn2.c

inherit ROOM;

void create()
{
        set("short", "����ʯ��");
        set("long", @LONG
����ͨ���Ǳ���ʯ�֣�����ʯ��ȫ���þ޴�Ļ��������ɵġ�
������ʯ·�����ѱ����Ǳ����˵ĸ��к����ơ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	  "down" : __DIR__"base_b_m",
          "up" : __DIR__"gate_castle",
          "west" : __DIR__"rope_bridge",
          ]));
          
          set("outdoors", "chuenyu");
          
          setup();
}
                  
