// Room: /d/chuenyu/rope_bridge.c

inherit ROOM;

void create()
{
// this place can check on player's dodge, if toolow, drop them!
        set("short", "������");
        set("long", @LONG
ɽ��ǿ���ķ紵�����������һζ������µ�������Ԩʹ��ͷ��Ŀ����
��߾�ȫ����ά������ƽ�⡣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"high_b_mtn",
          "east" : __DIR__"high_b_mtn2",
          ]));
          set("objects", ([
          __DIR__"npc/jiading3" : 2,
          ]) );
          
          
          set("outdoors", "chuenyu");
          
          setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        if( !arg || arg!="chain" ) 
	{
	     write("����ֻ��һ��������chain����\n");
             return 1;
	}

        message_vision("$Nץ��������˳��������������ȥ��\n",
                this_player() );
        this_player()->move(__DIR__"base_b_m");

        return 1;
}
                  
