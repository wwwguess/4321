inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
���߸ߴ�����Ĺ�ľ���γ�����Ȼ�����ϣ��ټ��ϵ��ƽ��ͣ�
���˿��Բµ���·����ͨ��η���ǰ���Ȼ������һ��ɽ����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"smallroad4",
  "west" : __DIR__"cave_tunnel",
]));
        set("outdoors", "resort");

        setup();
        replace_program(ROOM);
}
