inherit ROOM;

void create()
{
        set("short", "���̵�С��ƺ");
        set("long", @LONG
С��ƺ�޼��ĺ����롣���滹����Сͯ��ˣ���ĺۼ�������
���涼�����ｨ�������ǵ���԰��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "east" : __DIR__"home",
          "south" : __DIR__"dustyroad3",
          ]));
          set("objects", ([
           __DIR__"npc/frog" : 2,
           __DIR__"npc/ant"  : 2,
           __DIR__"npc/fly"  : 2,
           ]) );
           set("outdoors", "chuenyu");
           setup();
}
                   