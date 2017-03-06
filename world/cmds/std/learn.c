// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "˵������̫�����ˣ�������ҵ���\n",
        "�����ܳ�����һ����˵������̣�������ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲ�᣿\n",
});

int is_appr_of(object me, object master);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string skill, teacher, master;
        object ob, *list , couple_ob;
        int master_skill, my_skill, gin_cost;
	string target, cardname;
	int i,marry_flag;

        if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
                return notify_fail("ָ���ʽ��learn <����> from <ĳ��>\n");

        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("��Ҫ��˭��̣�\n");

        if( !living(ob) )
                return notify_fail("��....����Ȱ�" + ob->name() + 
"Ū����˵��\n");

	marry_flag = 0;
	list = all_inventory(me);
	i = sizeof(list);
	while (i--) {
		if ((string)list[i]->query("id") == "marrycard") {
			cardname = list[i]->query("name");
			marry_flag = 1;
		}
	}
	if ( marry_flag ==1 ) {	
		if (sscanf(cardname,"���%s�Ļ�Լ" ,target)!=1)
                	return notify_fail("��û�а���.\n");
			couple_ob = find_player(target);	
	}
 
       
	// if( !me->is_apprentice_of(ob) ) {
	if (!is_appr_of(me, ob)) {
		if (couple_ob != ob) {
                if( (string)me->query("family/family_name") != 
(string)ob->query("family/family_name")
                ||      (int)ob->query("family/privs") != -1 ) {
                        notify_fail( ob ->name() + 
reject_msg[random(sizeof(reject_msg))] );
                        if( !(ob->recognize_apprentice(me)) ) return 0;
                }
		}
        }

        if( !master_skill = ob->query_skill(skill, 1) )
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");

        notify_fail(ob->name() + "��Ը���������ܡ�\n");
        if( ob->prevent_learn(me, skill) )
                return 0;

        my_skill = me->query_skill(skill, 1);
        if( my_skill >= master_skill )
                return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");

        notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
        if( !SKILL_D(skill)->valid_learn(me) ) return 0;

        gin_cost = 150 / (int)ob->query("int") + 150 / (int)me->query("int");

        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }

        if( (int)me->query("learned_points") >= (int)me->query("potential") )
                return 
notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
        printf("����%s����йء�%s�������ʡ�\n", ob->name(),
                to_chinese(skill));

        if( ob->query("env/no_teach") )
                return notify_fail("����" + ob->name() + 
"���ڲ���׼���ش�������⡣\n");

        tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",
                me->name(), to_chinese(skill)));

        if( (int)ob->query("sen") > gin_cost/5 + 1 ) {
                if( userp(ob) ) ob->receive_damage("sen", gin_cost/5 + 1);
        } else {
                write("����" + ob->name() + 
"��Ȼ̫���ˣ�û�а취����ʲ�ᡣ\n");
                tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + 
"��\n");
                return 1;
        }
                

        if( (int)me->query("gin") > gin_cost ) {
                if( (string)SKILL_D(skill)->type()=="martial"
                &&      my_skill * my_skill * my_skill / 10 > 
(int)me->query("combat_exp") ) {
                        
printf("Ҳ����ȱ��ʵս���飬���%s�Ļش������޷���ᡣ\n", ob->name() );
                } else {
                        printf("������%s��ָ�����ƺ���Щ�ĵá�\n", 
ob->name());
                        me->add("learned_points", 1);
				me->improve_skill(skill, random(me->query("int")+me->query("combat_exp")/(1000+me->query("combat_exp")/1000)));
	
                }
        } else {
                gin_cost = me->query("gin");
                write("�����̫���ˣ����ʲ��Ҳû��ѧ����\n");
        }

        me->receive_damage("gin", gin_cost );

        return 1;
}

int is_appr_of(object me, object master)
{
	if (me->query("family/master_id") != master->query("id"))
		return 0;

	if (me->query("family/generation") != master->query("family/generation")+1) {
		message_vision("$n������Ҫɱ��$N\n",master,me);
		return 0;
		}

	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : learn <����> from <ĳ��>
 
���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����

ͨ����һ���˸�ѧ��һ���¼����ǲ�����ʲ����������ģ����Ǿ���ʵ���ϵ�Ӧ����
�������⣬��Щ������ѧϰһ���¼��ܵĹ����Ǻ���Ҫ�ģ������Ǹ�����Ϊ������
�ܻ����Ļ������ܣ�����Ҫ���ɡ��������⡪������⡹�Ĺ��̲��ܵõ��Ϻõ�Ч��
������ǽ����ַ�������Ĺ����á�Ǳ�ܡ��Ĺ����ʾ��һ�����ܹ��Լ�����ĳЩ��
�⣬��ʾ��(��)�н�����������Ǳ�ܣ��������������Ǳ��ʱ�Ϳ����������ָ��
������������̣�����ý�����
(PS. Ǳ�ܻ�������������Ķ��壬����ֻ������֮һ )

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�

������֪�����ܴӶԷ�ѧ��ʲ�Ἴ�ܣ�����Է������ʦ���������� skills ָ��
ֱ�Ӳ鿴������������ʦ��������ͨ��������������ʾ����ֻ���Լ���취��

�������ָ�� : practice��study
HELP
        );
        return 1;
}
 
