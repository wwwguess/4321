#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "���겻ɢ",
                "action":               "$Nʹһ�С����겻ɢ��������$w���Ⱪ����
 ��$n��$l��ȥ",
                 "dodge":                50,
                 "damage":               170,
                 "damage_type":  "����"
         ]),
        ([      "name":                 "����ɭɭ",
                "action":               "$N������ת��һ�С�����ɭɭ������$n��$l",
                 "dodge":                -70,
                 "damage":               20,
                 "damage_type":  "����"
         ]),
        ([      "name":                 "���Ƶ���",
                "action":               "$N�趯$w��һ�С����Ƶ���Ю����������
����$n��$l",                
                 "dodge":                -40,
                 "damage":               90,
                 "damage_type":  "����"
         ]),
        ([      "name":                 "���ܵظ�",
                "action":               "$N����$w����һ�������������ܵظ�����$n
��$l�̳�����",                
                 "dodge":                -40,
                 "damage":               40,
                 "damage_type":  "����"
         ]),
        ([      "name":                 "��������",
                "action":               "$N����$w���Ⱪ����һ�С��������ǡ���$n$l
��ȥ",
                 "dodge":                60,
                 "damage":               120,
                 "damage_type":  "����"
         ]),
        ([      "name":                 "��������",
                "action":               "$N����$w����һ���⻡��ֱָ$n$l��һ�С�
�������¡���������������ȥ",
                 "dodge":                -60,
                 "damage":               150,
                 "damage_type":  "����"
         ]),
});

int valid_learn(object me)
{
        object ob;
        if( (string)me->query("gender") != "Ů��" )
                 return notify_fail("��������������ֻ��Ů�Ӳ��������书��\n");
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취����������������\n");
        if( (string)me->query_skill_mapped("force")!= "nine-moon-force")
                 return notify_fail("������������������Ͼ����ľ���������\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");
                
        return 1;
}
        
int valid_enable(string usage)
{
         return usage=="sword" || usage=="parry";
}
        
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ������������\n
");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ���������������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("nine-moon-sword", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n��ͻȻ����һ������������ͷ��ֻ������ɱ��....\n\n"
  NOR);
                 me->add("bellicosity", 2000);
        } else
                me->add("bellicosity", 200);
}
string perform_action_file(string action)
{
        return CLASS_D("ninemoon") + "/ninemoonsword/" + action;
}

                                                                
                                                                                  