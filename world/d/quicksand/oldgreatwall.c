inherit ROOM;

void create()
{
        set("short", "�ƾɳ���");
        set("long", @LONG
������ΰ�ĳ�������Ŀȫ�ǣ����º�ս���Ѽ���������Ϊƽ�ء�Ψһ��
���һ����棬��������Ӣ�۵���ѪȾ�ɰ���ɫ��������Ȼ��һƬ��ɱ��
ȴ�м���С������ʯ�ķ�϶�м�����������һ�������ĸо���
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"saikou",
  "west" : __DIR__"saiwai",
]));
        set("outdoors", "quicksand");

        setup();
        replace_program(ROOM);
}
