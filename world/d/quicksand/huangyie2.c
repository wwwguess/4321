inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١�����
��������綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ�������Ǳ���
ѪȾ���һ����һ���������۵Ĺٵ��������Ͷ�����չ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"huangyie1",
  "west" : __DIR__"huangyie3",
]));
        set("outdoors", "quicksand");

        setup();
        replace_program(ROOM);
}
