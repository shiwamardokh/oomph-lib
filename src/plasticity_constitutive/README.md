# plasticity_constitutive

Finite-strain plasticity **constitutive laws**: yield criteria, hardening laws,
the return map, and the consistent (algorithmic) tangent. Stateless, all
history passes in and out through the state bundle.

for now: von Mises (J2), isotropic hardening, log-strain / exponential-map return map.
Meets the element layer only at:

    compute_response(F, state_n) -> (stress, state_np1, tangent)
