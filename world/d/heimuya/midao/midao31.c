//Room:/d/heimuya/midao/midao31.c 
//write by dfbb@hero
//Date: 1/25/96
inherit ROOM;

void create()
 {
        set("short", "�����ܵ�");
        set("long", @LONG ����������,ֻ��ǽ���ϵ���һյ�谵���͵�
 ��ʪ����ζ����ʮ�ֲ����,ֻ�����߳������ط�.
LONG );
        set("exits", ([
          "east" : __DIR__"midao32",
           "south" : __DIR__"midao41",
           "west" : __DIR__"midao30",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

