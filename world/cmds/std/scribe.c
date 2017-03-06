// scribe.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string spells, name, ob_name, opp;
	object ob;

	// We might need to load new objects.
	seteuid(getuid());

	if( me->is_fighting() )	return notify_fail("ս��ʱ���ܻ�����\n");
	if( (int)me->query("sen") < 30 )
		return notify_fail("��ľ���̫���ˣ��޷�������\n");

	if( !arg
	||	sscanf(arg, "%s on %s for %s", name, ob_name, opp)!= 3 )
		return notify_fail("ָ���ʽ��scribe <����> on <��Ʒ>\n");

	if( !objectp(ob = present(ob_name, me)) )
		return notify_fail("������û������������\n");

	if( stringp(spells = me->query_skill_mapped("spells")) ) {
//		notify_fail("����ѧ�ķ���û�����ַ���\n");
//		if( SKILL_D(spells)->scribe_spell(me, ob, name) ) {
		if( (SKILL_D(spells)->scribe_spell_file(name))->scribe(me, ob, opp) ) {
			me->receive_wound("kee", 1);
			me->receive_damage("sen", 30);
			return 1;
		}
		return 0;
	} else 
		return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ�����ϵ��\n");

	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ��scribe <��������> on <��Ʒ����> [for <����>]

�ڻ����õ��ҷ�ֽ(paper seal)��������Ʒ�ϻ�������ʹ����ͬ�ķ��䣬���ڲ�
ͬ����Ʒ��Ҳ�п����в�ͬ��Ч����

���㻭��֮ǰ����������� enable ָ����ָ����Ҫʹ�õ�����ϵ��

ע������������������(Ҫҧ����ָ����Ѫ��)���񣬻��ɵķ�������� attach
    ָ�������Ŀ�������ϡ�
 
HELP
        );
        return 1;
}
