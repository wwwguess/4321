
// selflearn.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string skill;
        int level, gin_cost;

        if(!arg || sscanf(arg, "%s", skill)!=1 )
                return notify_fail("ָ���ʽ��selflearn <����> \n");

	if ( skill != "dodge" && skill !="force" && skill != "sword" &&
	     skill != "blade" && skill !="staff" && skill != "parry" && skill != "unarmed" )
		return notify_fail("����ܲ���ͨ����ѧȡ�ý�����\n");

        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

	if ( (int)me->query_skill(skill,1) < 40  )  {
		printf("����С�%s��������֪ʶ���С�",to_chinese(skill));
		return notify_fail("\n");
	}

        gin_cost = 300 / (int)me->query("int");

        if( (int)me->query("learned_points") >= (int)me->query("potential") )
                return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");

        printf("�㿪ʼ�����йء�%s�������⡣\n", to_chinese(skill));
	level = (int)me->query_skill(skill,1);

        if( (int)me->query("gin") > gin_cost ) {
                if( level * level * level / 10 > (int)me->query("combat_exp") ) {
			printf("Ҳ����ȱ��ʵս���飬�����һ������\n" );
                } else {
                        printf("���˼ڤ�룬�ƺ���Щ�ĵá�\n");
                        me->add("learned_points", 1);
                        me->improve_skill(skill, random(me->query("int")+level));
                }
        } else {
                gin_cost = me->query("gin");
                write("�����̫���ˣ����ʲ��Ҳû��ѧ����\n");
        }

        me->receive_damage("gin", gin_cost );

        return 1;
}

