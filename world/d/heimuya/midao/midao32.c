//Room:/d/heimuya/midao/midao32.c 
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
          "east" : __DIR__"midao33",
           "south" : __DIR__"midao42",
           "west" : __DIR__"midao31",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

