
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("�ܺ�", ({ "secret letter","letter"  }) );
    set("unit", "��");
    set("long","����һ�������ܷ��������ż���������һ��ֵ�ͼ����\n");
    set_weight(50);
    setup();
}
void init()
{
             seteuid(getuid(environment()));
             add_action("do_fire","fire");
}

int do_fire(string arg)
{
       object me,obj;
       string item;

       me = this_player();
       item = "fire";
       if( !objectp(obj = present(item, me)) )
           return notify_fail("������û�л�û���ա�\n");
       tell_object(me, HIY "�㿴���ܺ��ϳ��ּ����� : \n" +
           HIM "ʦ��: \n" +
               "      չ������ \n" +
               "    ͽ��������ׯ��������һ������!\n" +
               "����ͽ�������з�������ׯ�����ܡ�\n" +
               "һ��ԭ������ׯ����ͬ���������ƺ��ڶ�����ʧ��֮�ţ�\n" +
               "    �Ա��Լ�����Ĺ����ɺ�ת����һ�ֱ�����͵İ���\n" +
               "����������֮�в���һ���š��Լ�ׯ����һ�������汦��\n" +
               "    �����������һ���صĵط���ͨ��ׯ���������˵�\n" +
               "    ������ڡ�\n" +
               "������ׯ��С�������л����������С�����ƺ�������\n" +
               "    ����������ͷ��\n" +
               "\n\n" NOR);
       return 1;
}
